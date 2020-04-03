#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int pipe1[2], pipe2[2]; // Used to store two ends of first pipe and second pipe
    
    pid_t p;
    
    if (pipe(pipe1)==-1){ //nilai failure
        fprintf(stderr, "Pipe Failed" ); //menampilkan message error
        return 1;
    }
    
    if (pipe(pipe2)==-1){ //nilai failure
        fprintf(stderr, "Pipe Failed" ); //menampilkan message error
        return 1;
    }
    
    p=fork();

    if (p< 0){
        fprintf(stderr, "Fork Failed" ); //error, tidak dapat dibentuk
        return 1;
    }else if (p > 0) {
        close(pipe2[0]); //menutup pipe
        close(pipe2[1]); //menutup pipe
        
        dup2(pipe1[0], 0);//membaca isi dr pipe 1 untuk dieksekusi        
        
        dup2(pipe2[1], 1); //output ke pipe 2

        close(pipe1[0]); //menutup write pipe
        close(pipe1[1]);

        char *argv[] = {"wc", "-l", NULL}; //mengetahui list jumlah file dan folder di direktori saat ini
        execvp("/usr/bin/wc", argv); // argumen list jumlah file dan folder
        exit(0);
    }else{ //jika fork()==0
        dup2(pipe1[1], 1);
        close(pipe1[0]);
        close(pipe1[1]);
        char *arg2[] = {"ls", NULL}; //fungsi list
        execvp("/bin/ls", arg2);  //argmumen list
    }
}