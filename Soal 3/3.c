#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

char buf[PATH_MAX+1];
char path[PATH_MAX+1], *p;
char *nama_file;
char *alamat_file;
char destpath[1024];
void *fungsi_f(void *arg);
pthread_mutex_t lock;

// fungsi buat mencari path dari file c
void path_c(char *str){
  FILE *fp;
  char buf[4096], *p;

  *str = '\0';
  if(!(fp = fopen("/proc/self/maps", "r")))
    return;

  fgets(buf, sizeof(buf), fp);
  fclose(fp);

  *(p = strchr(buf, '\n')) = '\0';
  while(*p != ' ')
    p--;

  strncpy(str, p+1, PATH_MAX);
  str[PATH_MAX] = '\0';
}

// list semua file yang ada di direktori file c dan dimasukkan di file "list_file.txt"
void list_file(char *path){

    FILE *f = fopen("list_file.txt", "w");
    if (f == NULL)
    {
        printf("Error dalam membuka file\n");
        exit(1);
    }

    DIR *d;
    struct dirent *dir;
    
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == DT_REG)
                fprintf(f, "%s/%s\n", path, dir->d_name);
        }
    closedir(d);
    fclose(f);
    }
}

// fungsi scan per line di list_file.txt
void read_path() {
  FILE* filePointer;
  int bufferLength = 255;
  char buffer[bufferLength];
  
  // Variabel flag buat simpan path list_file.txt
  char *flag;

  filePointer = fopen("list_file.txt", "r");

  while(fgets(buffer, bufferLength, filePointer)) {
    // printf("%s\n", buffer);

    flag = buffer;
    if (strcmp(buffer, "list_file.txt"))
    {
      /* code */
    }
    
  }

  fclose(filePointer);
}

// fungsi cari ekstensi file
char *cari_ekstensi(char *filename) {
  char *dot = strrchr(filename, '.');
  // printf("%s\n", dot);

  if(!dot || dot == filename)
    return 0;
  
  return dot + 1;
}

// fungsi cek dan buat folder
void cek_folder(char *foldername){
  struct stat st = {0};

  if (stat(foldername, &st) == -1) {
    mkdir(foldername, 0700);
  }
}

// fungsi buat move file
void* move_file(char *pathc, char *ekstensi, char *nama_file, char *alamat_asal){
  char destpath[1024];
  snprintf (destpath, sizeof(destpath), "%s%s/%s", pathc, ekstensi, nama_file);

  printf("Asal: %s\nDestinasi: %s\n", alamat_asal, destpath);

  if (rename (alamat_asal, destpath)) {
    // something went wrong
    if (errno == EXDEV) {
        // copy data and meta data 
    } else { perror("rename"); exit(EXIT_FAILURE); };
  } 
  else { // the rename succeeded
  }
}

void *fungsi_f(void *arg){
  // Lock mutex
  pthread_mutex_lock(&lock);

  // 1. Ambil nama file
  nama_file = strrchr((char *)arg, '/') + 1;
  alamat_file = (char *)arg;

  printf("Nama file: %s\n", nama_file);

  // 2. Cari ada ekstensi nya atau gak
  if(cari_ekstensi(nama_file)){ 
    cek_folder(cari_ekstensi(nama_file)); // Cek kalau gaada folder ekstensi
    move_file(path, cari_ekstensi(nama_file), nama_file, alamat_file); // Move file ke folder ekstensi
  }else{ 
    cek_folder("Unknown"); // Cek kalau gaada folder "Unknown"
    move_file(path, "Unknown", nama_file, alamat_file); // Move file ke folder "Unknown"
  }

  // Unlock mutex
  pthread_mutex_unlock(&lock);

  return NULL;
}

int main(int argc, char **argv)
{
  path_c(buf);

  strcpy(path, buf);
  if((p = strrchr(path, '/')))
    *(p+1) = '\0';
  
  // printf("Path file c: %s\n", path);

  int i = 2;
  pthread_t tid[argc - 1];

  // Error handling jika tidak ada argumen yang di input
  if (argc == 0)
  {
    printf("Mohon masukkan argumen pada program (-f, *, atau -d)");
    exit(EXIT_FAILURE);
  }
  
  // Error handling mutex
  if (pthread_mutex_init(&lock, NULL) != 0)
  {
    printf("Gagal buat mutex\n");
    return 1;
  }
  
  // Testcase tiap argument
  if(strcmp(argv[1], "-f") == 0){
    printf("Masuk ke -f\n");
    
    // buat thread
    while (i < argc)
    {
      pthread_create(&(tid[i]), NULL, fungsi_f, (void *)argv[i]);
      i++;
    }

    // wait thread kedua dst
    for (i = 2; i < argc; i++)
    {
      pthread_join(tid[i], NULL);
    }

  }else if(strcmp(argv[1], "*") == 0){
    printf("Masuk ke *\n");
  }else if(strcmp(argv[1], "-d") == 0){
    printf("Masuk ke -d\n");

    // Error handling ketika path directory yang dimasukkan lebih dari 1
    if (argc == 4)
    {
      printf("Mohon hanya memasukkan satu path directory!");
      exit(EXIT_FAILURE);
    }
    
    // List semua path dari file untuk kemudian diproses oleh thread
    list_file(argv[2]);
    read_path();
  }

  return 0;
}
