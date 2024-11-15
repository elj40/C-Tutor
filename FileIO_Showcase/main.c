#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <string.h>
#include <ctype.h>

struct Student {
    int age;
    float aura;
    char name[15];
    int drip;
};

void print_student(struct Student s) {
    printf("Name: %15s, age: %d, aura: %.2f, drip: %2d\n", s.name, s.age, s.aura, s.drip);
}

int main()
{
    srand(time(0));
    struct Student students[10];

    FILE * student_file = fopen("students.bin", "rb");
    // SEEK_SET (from start of file),
    // SEEK_CUR  (from current position),
    // SEEK_END (from the end of the file)
    // offset: how many spaces


    fread(&students[0], sizeof(struct Student), 10, student_file);

    printf("Old Students\n");
    for (int i = 0; i < 10; i++) {
        print_student(students[i]);
    }

    struct Student first;
    struct Student last;

    fseek(student_file, 0, SEEK_SET);
    fread(&first, sizeof(struct Student), 1, student_file);

    fseek(student_file, -1*sizeof(struct Student), SEEK_END);
    fread(&last, sizeof(struct Student), 1, student_file);

    printf("\nFirst and last students:\n");
    print_student(first);
    print_student(last);

    fclose(student_file);

    student_file = fopen("students.bin", "wb");

    printf("\nNew students: \n");
    for (int i = 0; i < 10; i++) {
            // 18 to 25, exclusive
        int age = rand() % 7 + 18;
        // 1-10 inclusive
        int drip = rand() % 10 + 1;
        int name_choice = rand() % 2;

        if (name_choice == 0) {
            strncpy(students[i].name, "Alex", 15);
        } else {
            strncpy(students[i].name, "Darryl", 15);
        }
        // 0..1
        float aura = (float) rand() / RAND_MAX;

        students[i].age = age;
        students[i].aura = aura;
        // = name;
        students[i].drip = drip;

        print_student(students[i]);
    }



    fwrite(students, sizeof(struct Student), 10, student_file);

    fclose(student_file);



    return 0;
    // fopen(filename, what are we gonna do with the file) gives a pointer to a file
    // pointer is at the position in the "file"

    // feof(file_pointer) check if we have reached end of file

    // fread(pointer to a variable where we are going to store what we read,
    //      ,how many bytes should i read (whats the size that i must read)
        //  ,how long is the array i am writing into
        //  ,pointer to the file)

    //fwrite(pointer to a variable that we want to write to file,
    //      ,how many bytes should i write (whats the size that i must write)
        //  ,how long is the array i am that you have given
        //  ,pointer to the file)


    // fclose(file pointer) closes the file stream




    // Reading text from a file
    FILE * lorem_file = fopen("lorem.txt", "r");
    if (lorem_file == NULL) {
        printf("Could not open write file!\n");
        return 1;
    }
    while (!feof(lorem_file)) {
        char c;
        char * cp = &c;

        char ten_chars[11];
        // fread arguments: fread(pointer to variable, size of what i must read, how long is your array, file pointer)
        fread(ten_chars, sizeof(char), 10, lorem_file);
        ten_chars[10] = '\0';
        printf("%s\n", ten_chars);
    }

    printf("Hello world!\n");

    fclose(lorem_file);

    // Writing to a text file
    FILE * my_out_file = fopen("some_new_file.txt", "w");

    if (my_out_file == NULL) {
        printf("Could not open write file!\n");
        return 1;
    }

    char * my_message = "Howdy!";
    char mello[] = "Meeeeseeeks";

    printf("Writing to file...\n");
    // fwrite(pointer to array/variable
    fwrite(my_message, sizeof(char), strlen(my_message), my_out_file);

    fclose(my_out_file);

    // Can we capitalise all the letters from lorem_file and write it into a lorem_capitalised.txt file?
    FILE * lorem_cap_file = fopen("PAIN_ITSELF.TXT", "wb");
    lorem_file = fopen("lorem.txt", "r");

    while (!feof(lorem_file)) {
        char c;
        //reading lower case
        fread(&c, sizeof(char), 1, lorem_file);
        //write upper case
        char upper_c = toupper(c);
        fwrite(&upper_c, sizeof(char), 1, lorem_cap_file);
    }
    fclose(lorem_file);
    fclose(lorem_cap_file);


    return 0;
}
