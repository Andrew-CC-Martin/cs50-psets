#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void bubble_sort(candidate candidates[]);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    bubble_sort(candidates);

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Early exit if no name
    if (!name)
    {
        return false;
    }

    bool found_candidate = false;

    // Note - this is O(n), but could be reduced to O(logn) if candidates
    // were sorted by name, and name found by binary search
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            found_candidate = true;
        }
    }


    return found_candidate;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int highest_count = 0;

    // Note - this is O(2n), but could be reduced to O(n)
    // if candidates were reverse sorted by votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > highest_count)
        {
            highest_count = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == highest_count)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

void bubble_sort(candidate candidate_array[])
{
  int any_swapped = 1;
  int length = 0;

  while(any_swapped) {
    any_swapped = 0;

    for (int i = 0; i < (candidate_count - 1); i++) {
      if(candidate_array[i].name[0] > candidate_array[i + 1].name[0]) {
        string temp = candidate_array[i].name;
        candidate_array[i].name = candidate_array[i + 1].name;
        candidate_array[i + 1].name = temp;
        any_swapped = 1;
      }
    }
  }
}

