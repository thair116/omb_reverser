
#include <stdio.h>
#include <ctype.h>

main() {

  const int  BUFFER_SIZE = 10;

  printf( "Enter a sentence.\n");

  char buffer[BUFFER_SIZE];
  int i = 0;
  int overflow_count = 0;
  char c = getchar( );


  do{
    if(isalpha( c )) {
      buffer[i] = c;
      i++;
      // if buffer is full, dump it
      if(i >= BUFFER_SIZE) {
        overflow_count ++;
        char filename[20];
        sprintf(filename, "/tmp/overflow_%d", overflow_count);
        FILE *fp = fopen(filename, "w+" );

        for (int j = i - 1; j >= 0; j--) {
          fputc( buffer[j], fp );
        }

        fclose(fp);
        // reset buffer index
        i = 0;
      }
    }
    // if delimiting character, print buffer in reverse
    if(c == EOF || c == ' ' || c == '\n') {

      for (int j = i - 1; j >= 0; j--) {
        putchar(  buffer[j] );
      }
      // reset buffer index
      i = 0;

      // if overflow exists:
      //    print most recent overflow in reverse order
      //    delete that overflow
      //    continue until no more overflows exist
      if(overflow_count > 0){
        for(int j = overflow_count; j > 0; j--){
          char overflow[10];
          char filename[20];
          sprintf(filename, "/tmp/overflow_%d", overflow_count);
          FILE *fp = fopen(filename, "r" );

          fscanf(fp, "%s", overflow);
          for (int j = 0; j < BUFFER_SIZE; j++) {
            putchar(  overflow[j] );
          }
          fclose(fp);
          if(remove(filename) == -1) {
            perror("Error in deleting a file");
          }
          overflow_count --;
          }
        }

        // print a space to separate words
        putchar(' ');
      }

      c = getchar( );

  }
  while(c != EOF);
}
