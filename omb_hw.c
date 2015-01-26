
#include <stdio.h>
#include <ctype.h>

main() {

  printf( "Enter a sentence.\n");

  int m = 5;

  // char c = getchar( );
  // char* buffer = calloc(10, sizeof(char));
  char buffer[10];
  // index for next available space in buffer
  int i = 0;
  // count of buffer overflow chunks
  int overflow_count = 0;

  // int last_run = 0;

  while(1 == 1){
    char c = getchar( );
    // if char is not space:
    //   add it to the buffer
    if(isalpha( c )) {
      // printf("character: %c index: %d\n", c, i);

      buffer[i] = c;
      i++;

      // printf("Buffer: %s", buffer);
      // printf("\n");
      // printf("Raw buffer:\n");
      // for (int j = 0; j < 10; j++) {
      //   // putchar(  buffer[j] );
      //   // printf("%c", buffer[j]);
      //   printf("%i ", buffer[j]);
      // }
      // printf("\n");
      // printf(" -- i: %i", i);
      // printf(" -- c: %c", c);
      // printf("\n");
      // printf("Saved %c in buffer\n", buffer[i-1]);
      // printf("Current buffer: %s -- ", buffer);
      // for (int j = 0; j < i; j++) {
      //   putchar(  buffer[j] );
      // }
      // printf("\n");
      // putchar(  buffer[j] );

      // if buffer is full
      //    save buffer
      if(i >= 10) {
        // printf("trying to save\n");
        // save_buffer;
        overflow_count ++;
        char filename[20];
        sprintf(filename, "/tmp/overflow_%d", overflow_count);
        // printf("filename: %s\n", filename);
        // printf("trying to open filename %s\n", filename);

        // open and read file
        FILE *fp = fopen(filename, "w+" );
        // printf("printing buffer: %s\n", buffer);

        for (int j = i - 1; j >= 0; j--) {
          // putchar(  buffer[j] );
          // printf("%c", buffer[j]);
          fputc( buffer[j], fp );
        }

        // fprintf(fp, buffer);
        fclose(fp);
        // clear buffer
        i = 0;
        // free(buffer);
        // buffer[0] = '\0';
      }
    }
    // if char is space:
    //   print buffer in reverse
    if(c == EOF || c == ' ' || c == '\n') {
      // printf(" -- m: %i", m);
      // int k = 5;
      // printf(" -- k: %i\n", k);
      // printf("Buffer: %s", buffer);
      // printf("\n");
      // printf("Raw buffer:\n");
      // for (int j = 0; j < 10; j++) {
      //   // putchar(  buffer[j] );
      //   // printf("%c", buffer[j]);
      //   printf("%i ", buffer[j]);
      // }
      // printf("\n");
      // printf(" -- i: %i", i);
      // printf(" -- c: %c", c);
      // printf(" ||\n");
      //
      // printf(" -- m: %i\n", m);
      // printf(" -- k: %i\n", k);
      // printf(" -- m: %i\n", m);
      // printf(" -- k: %i\n", k);
      // printf(" -- m: %i\n", m);
      // printf(" -- k: %i\n", k);
      // printf(" -- m: %i\n", m);
      // printf(" -- m: %i\n", m);
      // printf(" -- m: %i\n", m);
      // m = 6;
      // printf(" -- m: %i\n", m);

      for (m = i - 1; m >= 0; m--) {
        // printf(" -- m: %i\n", m);
        putchar(  buffer[m] );
      }
      i = 0;

      // printf("\nmade it to here\n");

      // if overflow exists:
      //    print most recent overflow in reverse order
      //    delete that overflow
      //    continue until no more overflows exist
      if(overflow_count > 0){
        // printf("made it down here\n");
        for(int j = overflow_count; j > 0; j--){
          char overflow[10];

          // get overflow filename
          // printf("made it in here\n");
          // printf(" -- overflow_count: %i\n", overflow_count);

          char filename[20];
          sprintf(filename, "/tmp/overflow_%d", overflow_count);
          // printf("filename: %s\n", filename);
          // open and read file
          FILE *fp = fopen(filename, "r" );

          fscanf(fp, "%s", overflow);
          // print overflow
          // reverse_print(overflow);
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
        printf("closing.");
        break;
      }

    // if(last_run == 1){
    //   break;
    // }
    // c = getchar();
    // if(c == '\n'){
    //   last_run = 1;
    //   // c = ' ';
    //   // printf("closing up\n");
    // }
  }
}
//
// // buffer to hold the word
// char buffer[10];
// // index for next available space in buffer
// int i = 0;
// // count of buffer overflow chunks
// int overflow_count = 0;
//
// // while more characters
// while (true){
//
//   // get the next character
//   int c = getchar( );
//
//   // if char is not space:
//   //   add it to the buffer
//   if(!isspace( c )) {
//
//     char buffer[i] = c;
//     i++;
//     // if buffer is full
//     //    save buffer
//     if(i >= 10) {
//       // save_buffer;
//       overflow_count ++;
//
//       char filename[] = "/tmp/overflow_"
//       strcat( filename, sprintf("%d", overflow_count));
//       // open and read file
//       FILE *fp = fopen(filename, "w+" );
//       fprintf(fp, buffer);
//       fclose(fp);
//     }
//   }
//   // if char is space:
//   //   print buffer in reverse
//   else {
//     // print buffer in reverse (from i-1 to 0)
//     // if i is zero, nothing will be printed (as desired)
//     // should not print null values
//     for (int j = i-1; j >= 0; j--) {
//       putchar(  buffer[j] );
//     }
//
//     // if overflow exists:
//     //    print most recent overflow in reverse order
//     //    delete that overflow
//     //    continue until no more overflows exist
//     if(overflow_count > 0){
//       for(int j = overflow_count; j >=0; j--){
//         char overflow[10];
//
//         // get overflow filename
//         char filename[] = "/tmp/overflow_"
//         strcat( filename, sprintf("%d", overflow_count));
//         // open and read file
//         FILE *fp = fopen(filename, "r" );
//         fscanf(fp, "%s", overflow);
//         // print overflow
//         // reverse_print(overflow);
//         for (int j = 9; j >= 0; j--) {
//           putchar(  overflow[j] );
//         }
//         // delete overflow
//         fclose(fp);
//         if(remove(filename) == -1)
//           perror("Error in deleting a file");
//         // decrement overflow_count
//         overflow_count --;
//
//       }
//     }
//
//     // print the space at the end of a word
//     char space = ' ';
//     putchar(space);
//   }
//
// }
// //
// // continue until no more characters exist
// //
// // best case (no overflow): 2N (add each char to buffer, then empty buffer )
// //
// // worst case (all overflow): N (add each to buffer)
// //
// //
// //
// //
// //
// // =========================
// //
// // function is given a stream of characters from stdin
// //
// // does not yet account for punctuation or newlines
// //
// //
//
