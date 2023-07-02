#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shortest_line_index(int lines[], int n) {
  int shortest_line_index = 0;
  for (int i = 1; i < n; i++) {
    if (lines[i] < lines[shortest_line_index]) {
      shortest_line_index = i;
    }
  }
  return shortest_line_index;
}

void assign_people(int n, int m, int lines[]) {
  int i, shortest;
  for (i = 0; i < m; i++) {
    shortest = shortest_line_index(lines, n);
    printf("Number of people in line %d: %d\n", shortest, lines[shortest]);
    lines[shortest]++;
  }
}

int main(void) {
  // n represents the number of lines.
  // m represents the number of new people.
  // n and m are at most 100;
  int n, m;
  printf("Enter the number of lines and number of new people\n");
  scanf("%d%d", &n, &m);
  printf("Number of lines: %d\n", n);
  printf("Number of new people: %d\n", m);

  // Represents the initial number of people for each line.
  int lines[n];
  printf("Enter the initial number of people for each line\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &lines[i]);
  }

  // For each of the m new people, output a line containing
  // the number of people in the line that they join. 
  assign_people(n, m, lines);
  return 0;
}
