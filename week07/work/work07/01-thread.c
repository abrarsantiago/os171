/*
 * (c) 2015-2016 Rahmat M. Samik-Ibrahim -- This is free software
 * Feel free to copy and/or modify and/or distribute it, 
 * provided this notice, and the copyright notice, are preserved. 
 * REV01 Wed Nov  2 11:49:39 WIB 2016
 * START Xxx Sep 30 XX:XX:XX UTC 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include "99-myutils.h"

sem_t	generik;
sem_t	generik2;

void* thread1 (void* a) {
   sem_wait   (&generik);
   printf("THREAD1: I am second!\n");
   sem_post   (&generik2);
}

void* thread2 (void* a) {
   printf("THREAD2: I am first!\n");
   sem_post   (&generik);
}

void* thread3 (void* a) {
   sem_wait   (&generik2);
   printf("THREAD3: I am last!\n");
}

void main(void) {
   sem_init      (&generik,  0, 0);
   sem_init      (&generik2, 0, 0);
   daftar_trit   (thread1);
   daftar_trit   (thread2);
   daftar_trit   (thread3);
   jalankan_trit ();
   beberes_trit  ("Bye Bye Main...");
}

