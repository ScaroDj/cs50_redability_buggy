#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int charNum(string input);
int wrdNum(string input);
int phrNum(string input);
//string testext(void);

int main(int argc, string argv[])
{
    bool debug = false, fltng = false;
    string input;

    // ========== grabbing input from the user ==========
    if(argc < 2)
    {
        input = get_string("Text: ");
    }
    else if(argc > 2)
    {
        if( strcmp(argv[1], "-d") == 0)
        {
            input = argv[2];
            printf("stats for nerds:\n");
            debug = true;
        }
        else if( strcmp(argv[1], "-f") == 0)
        {
            input = argv[2];
            fltng = true;
        }
        else
        {
            printf("Please try again by entering your text in between double quote signs.\n");
            return 0;
        }
    }
    else
    {
        input = argv[1];
    }

    /*
    printf("Source text: %s\n\n", input); //test the input:
    index = 0.0588 * L - 0.296 * S - 15.8
    L = Letters ÷ Words × 100 = 639 ÷ 119 × 100 ≈ 537
    S = Sentences ÷ Words × 100 = 5 ÷ 119 × 100 ≈ 4.20

    L is the average number of letters per 100 words
    S is the average number of sentences per 100 words
    list of a hundred words  |  list of number of letters on each word
    100                      |  total sum of letters
    avarage would be letterSum / 100

        since we might not have a 100 words
        find what to divide the letter sum by instesd o 100


    letterSum (x) --> ??? (y) as
    wordSum   (a) --> 100 (b)
    a ~ b = x ~ y
    y = b * x / a
    ??? = words * letters || sentences / 100
    */

    float letters = charNum(input);
    float words = wrdNum(input);
    float sentences = phrNum(input);

    float la = letters / words * 100;
    float sa = sentences / words * 100;
    float index = (0.0588 * la) - (0.296 * sa) - 15.8;

    // round index
    int cli = 1;
    if(fltng == true)
    {
        cli = index;
    }
    else
    {
        cli = round(index);
    }

    // ========== A section to print information to understand what happens ==========
    if(debug == true)
    {
        printf("%.0f letters %.0f words & %.0f sentenes\n", letters, words, sentences);

        // checking the falues for the formula
        printf("L = %.2f ÷ %.2f × 100 = %.2f\n", letters, words, la);
        printf("S = %.2f ÷ %.2f × 100 = %.2f\n", sentences, words, sa);
        printf("index = 0.0588 * %.4f - 0.296 * %.4f - 15.8 = %.4f rounded to %i\n", la, sa, index, cli);
    }

    // ==================== Print the results ====================
    if(cli < 1)   // if round_index is <1 print "Before grade 1"
    {
        printf("Before Grade 1\n");
    }

    else if(cli > 16)  // elif round_index is >16 print "Grade 16+"
    {
        printf("Grade 16+\n");
    }

    else    // else printf("Grade %s\n", result)
    {
        printf("Grade %i\n", cli);
    }
}

int charNum(string input)        // ========== count words ==========
{
    // count the number of letters, (spaces) and sentences (.!? marcs)
    int letters = 1;
    for(int i = 0, n = strlen(input); i <= n; i++)
    {
        if(isalpha(input[i]))
        {
            letters++;
        }
    }
    return letters;
}

int wrdNum(string input)        // ========== Cont words ==========
{
    int words = 1;
    for(int i = 0, n = strlen(input); i <=n; i++)
    {
        if(isspace(input[i]))
        {
            words++;
        }
    }
    return words;
}

int phrNum(string input)        // ========== Cont sentences ==========
{
    int sentences = 0;
    for(int i = 0, n = strlen(input); i <= n; i++)
    {
        if(input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
