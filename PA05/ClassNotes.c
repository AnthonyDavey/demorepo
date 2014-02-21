//Class notes --Structures and Binary Files

/*
fopen/fclose/fgetc/fputc/fgets/...
File*fp = ....
ASCII encoding (8 bit)

Binary -- no encoding.
	-Text: 16 -> becomes two characters [1] and [6] --> [49]&[54] in ASCII
	-Binary: 16 -> [16]
	
	fwrite and fread (takes a pointer)
*/

//Data Structures 
typedef struct{
	char *firstnam;
	char *lastname;
	int age;
} Student;

int main(int argc, char ** argv) //wrong way to do this
{
	#define DB_SIZE 100
	Student students[DB_SIZE]
	//...
	
	int i;
	for(i=0; i<DB_SIZE; i++)}
		//Student s = students[i];
		printf("first: %s\n", students[i].firstname);
		printf("last: %s\n", students[i].lastname);
		printf("age: %d\n", students[i].age);
		
		Student *s = &(students[i]);
		printf("first: %s\n", s->firstname);
		printf("last: %s\n", s->lastname);
		printf("age: %d\n", s->age);
		
		
	}
	
}


