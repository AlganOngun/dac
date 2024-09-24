#include <stdio.h>
#include "dac.h"

struct person {
	char *name;
	int age;
	char **kids;
};

void print_people(struct person *people)
{
	for (size_t i = 0; i < dac_len(people); ++i) {
		struct person person = people[i];
		printf("%s is %d years old and he has %d kids: \n", person.name,
		       person.age, (int)dac_len(person.kids));

		for (size_t i = 0; i < dac_len(person.kids); ++i) {
			printf("	%s\n", person.kids[i]);
		}
	}
}

int main(void)
{
	struct person jone = { .name = "Jone Johnson",
			       .age = 58,
			       .kids = NULL };
	dac_push(jone.kids, "Johnny Johnson");
	dac_push(jone.kids, "Richard Johnson");

	struct person joel = { .name = "Joel Bigman", .age = 95, .kids = NULL };
	dac_push(joel.kids, "Chad Bigman");

	struct person dante = { .name = "Dante Holy", .age = 36, .kids = NULL };
	dac_push(dante.kids, "Micheal Holy");
	dac_push(dante.kids, "Abraham Holy");
	dac_push(dante.kids, "Jacob Holy");
	dac_push(dante.kids, "Joseph Holy");

	struct person *people = NULL;
	dac_push(people, jone);
	dac_push(people, joel);
	dac_push(people, dante);

	print_people(people);
}
