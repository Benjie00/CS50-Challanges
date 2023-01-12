#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO

    // candidates and the ranks array both index to the same candidate --> therefore, when the name inputted by user == a candiate, the index is set = to j (the rank - where 0 is first choice). However this will keep stacking through the loop - so in turn the candiate with the lowest number is most prefered and so on.
    for (int k = 0; k < candidate_count; k++)
    {
        if (strcmp(name, candidates[k]) == 0)
        {
            ranks[k] = rank;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    // loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // when comapring the candiates the candidate with lower rank is prefered
        // assigning rank i to preference i all we are doing here is assigning a name to preferneces

        // loop through voters
        for (int j = 0; j < candidate_count; j++)
        {
            // condition --> if rank i (i corresponds to a specific candidate) is lower than j+1(another candidate), add 1 to preference i (still correspondst to the same candidate), thereofre talling votes
            if (ranks[i] < ranks[j])
            {
                // 2d array
                preferences[i][j]++;
            }
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    // add each pair to pairs array as long as one candidate is prefered over the other

    // loop over candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // sort into pairs
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                // comparing every combination of candidates (against them selves cancels out)

                // assigning winner
                pairs[i].winner = i;
                // assinging loser
                pairs[i].loser = j;
                // pair count increment
                pair_count++;
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory (strongest to least strong)
void sort_pairs(void)
{
    // TODO

    // sort method (selection sort)

    // loop until pair_count -1 because once we get to the last number it should be sorted already
    for (int i = 0; i < pair_count - 1; i++)
    {
        // setting index for min position
        int min_pos = i;

        for (int j = i + 1; j < pair_count; j++)
        {

            if (preferences[i][j] > preferences[j][i])
            {
                min_pos = j;
            }

            if (min_pos != i)
            {
                int temp = pairs[i] pairs[i] = min_pos;
                pairs[min_pos] = temp;
            }
        }
        for (int k = 0; k < pair_count; i++)
        {
            printf("pairs[%i] = %i\n", i, pairs[i]);
        }
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}