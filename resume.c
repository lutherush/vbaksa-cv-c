#include <stdio.h>
#include <time.h>
/*
* This is my CV in C
* Only reason why i made it is to stand apart from all otger developers.
* On my github you can find my resume as rust cli app, bash script and as npm package. If i will have time i will also make my resume as 
* interzctive web app, android/ios app and platform game
* this may show knowledge in
* pointers, structs and references
*/

typedef struct {
	union {
		char * company;
		char * school;
		char * project;
	};
	union {
		char * location;
		char * url;
	};
	union {
		char * title;
		char * program;
	};

	time_t started;
	time_t left;

	char * description[];
} thing_t;

typedef thing_t job_t;
typedef thing_t school_t;
typedef thing_t project_t;

#define CURRENT 0

/* Contact Information */
char * name    = "Velimir Baksa";
char * email   = "velimir.baksa@gmail.com";
char * address = "Located in:\n"
                 "Varazdin Croatia";

/* Education */
school_t ipla = {
	.school   = "University North",
	.location = "Varazdin",
	.program  = "Mechanical engineering",
	.started  = 2008,
	.left     = 2013,
	 NULL
	}
};

/* Education */
school_t coursera = {
	.school   = "Faculty of chemical engineering",
	.location = "Zagreb",
	.program  = "chemical engineering",
	.started  = 2005,
	.left     = 2008,
	 NULL
	}
};

/* Employment History */
job_t amaris = {
	.company  = "Asgard technology LLC",
	.location = "Pasadena CA, USA",
	.title    = "Software developer",
	.started  = 2019,
	.left     = CURRENT,
	.description = {
		"Senior softwre developer",
		NULL
	}
};
job_t hp = {
	.company  = "Dziro",
	.location = "London, UK",
	.title    = "CTO",
	.started  = 2019,
	.left     = 2020,
	.description = {
		"This job sucks I take it because i needed money to survive and basic idea was promissing.",
		"No programing at, no tech at all and CEO does not know how to finance and gorw a startup",
		NULL
	}
};

job_t eyc = {
	.company  = "RedSky",
	.location = "Dubai, UAE",
	.title    = "Softwre developer",
	.started  = 2017,
	.left     = 2018,
	.description = {
		"mprove the toolchain used internally to allow the usage of clang-tidy for the linting of our code",
		NULL
	}
};

job_t adem = {
	.company  = "Ht",
	.location = "Zagreb, Croatia",
	.title    = "Software analyst",
	.started  = 2015,
	.left     = 2016,
	.description = {
		"Static analysis of code",
		"Develop mdbuilder daemon in C",
		"Develop data transport components in php and after in python",
		"First python contact and build various PoC RPC services",
		"First look to SQLAlchemy Great framework experience",
		"Extend postfix with triggers in C and python",
		"Great expedition",
		NULL
	}
};



/* Projects */
project_t mdbuilder = {
	.project = "mdbuilder",
	.url     = "http://github.com/mnothic/mdbuilder",
	.title   = "Developer",
	.started = 1306886400,
	.left    = 1309516143,
	.description = {
		"Daemon in C to automate postfix smtp user manage in a database model, great expedition",
		"Automate build and delete folders structure for postfix+dovecot",
		NULL
	}
};

project_t growpy = {
	.project = "sara",
	.title   = "AI developer",
	.started = 2017,
	.left    = CURRENT,
	.description = {
		"AI navigationfor blind people",
		NULL
	}
};

/* Alma matér */
school_t * schools[] = {
	&ipla,
	NULL
};

/* profesional experience stack */
job_t * jobs[] = {
	&amaris,
	&hp,
	&eyc,
	&adem,
	NULL
};

/* github proyects */
project_t * projects[] = {
	&growpy,
	&mdbuilder,
	NULL
};

void print_thing(thing_t * thing) {
	char started[100];
	char left[100];
	struct tm * ti;

	printf("%s at %s - %s\n", thing->title, thing->company, thing->location);

	ti = localtime(&thing->started);
	strftime(started, 100, "%B %d, %Y", ti);

	if (thing->left == CURRENT)  {
		printf("%s to now\n", started);
	} else {
		ti = localtime(&thing->left);
		strftime(left,    100, "%B %d, %Y", ti);
		printf("%s to %s\n", started, left);
	}

	char ** desc = thing->description;
	while (*desc) {
		printf("- %s\n", *desc);
		desc++;
	}
}

int main(int argc, char ** argv) {

    printf("If you compiled this get full IT history about me...\n");
	printf("%s\n%s\n%s\n\n", name, email, address);

	puts("Education\n");
	school_t ** s = schools;
	while (*s) {
		print_thing(*s);
		puts("");
		s++;
	}

	puts("Employment History\n");
	job_t ** j = jobs;
	while (*j) {
		print_thing(*j);
		puts("");
		j++;
	}

	puts("Github Projects\n");
	project_t ** p = projects;
	while (*p) {
		print_thing(*p);
		puts("");
		p++;
	}

	return 0;
}
