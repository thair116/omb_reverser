
#include <stdio.h>
#include <ctype.h>

main() {

  printf( "Enter a sentence.\n");

  char buffer[10];
  // index for next available space in buffer
  int i = 0;
  // count of buffer overflow chunks
  int overflow_count = 0;

  while(1 == 1){
    char c = getchar( );
    // if char is not space:
    //   add it to the buffer
    if(isalpha( c )) {
      buffer[i] = c;
      i++;
      // if buffer is full
      //    save buffer
      if(i >= 10) {
        // save_buffer;
        overflow_count ++;
        char filename[20];
        sprintf(filename, "/tmp/overflow_%d", overflow_count);
        // open and read file
        FILE *fp = fopen(filename, "w+" );

        for (int j = i - 1; j >= 0; j--) {
          fputc( buffer[j], fp );
        }

        fclose(fp);
        // clear buffer
        i = 0;
      }
    }
    // if char is space:
    //   print buffer in reverse
    if(c == EOF || c == ' ' || c == '\n') {

      for (int j = i - 1; j >= 0; j--) {
        putchar(  buffer[j] );
      }
      i = 0;

      // if overflow exists:
      //    print most recent overflow in reverse order
      //    delete that overflow
      //    continue until no more overflows exist
      if(overflow_count > 0){
        // printf("made it down here\n");
        for(int j = overflow_count; j > 0; j--){
          char overflow[10];

          // get overflow filename

          char filename[20];
          sprintf(filename, "/tmp/overflow_%d", overflow_count);
          // open and read file
          FILE *fp = fopen(filename, "r" );

          fscanf(fp, "%s", overflow);
          // print overflow
          for (int j = 0; j < 10; j++) {
            putchar(  overflow[j] );
          }
          // delete overflow
          fclose(fp);
          if(remove(filename) == -1)
            perror("Error in deleting a file");
            // decrement overflow_count
            overflow_count --;

          }
        }

        // print the space at the end of a word
        putchar(' ');
      }

      if(c == EOF){
        break;
      }
  }
}
