#include <cstdio>
#include <cstring>
#include <cstdlib>


const size_t MAX_MESSAGE = 64;
char message[MAX_MESSAGE];
char correct[] = "Output is correct.\n";

FILE *in, *sol, *out;

void close_files() {
	if (in != nullptr) {
		fclose(in);
	}
	if (sol != nullptr) {
		fclose(sol);
	}
	if (out != nullptr) {
		fclose(out);
	}
}

void terminate() {
	close_files();
	std::exit(0);
}

void open_files(int argc, char **argv) {
	if (argc != 4) {
		fprintf(stdout, "0.0\nInvalid number of arguments\n");
		terminate();
	}
	in = fopen(argv[1], "r");
	sol = fopen(argv[2], "r");
	out = fopen(argv[3], "r");

	if ((in == nullptr) || (sol == nullptr) || (out == nullptr)) {
		fprintf(stdout, "0.0\nFailed opening files\n");
		terminate();
	} 
}

int main (int argc, char **argv) {
	open_files(argc, argv);

	float score;
	fgets(message, MAX_MESSAGE, out);

	if (std::strcmp(message, correct) == 0) {
		score = 1;
	} else {
		score = 0;
	}

	fprintf(stdout, "%f\n", score);
	fprintf(stderr, "%s", message);

	close_files();
}
