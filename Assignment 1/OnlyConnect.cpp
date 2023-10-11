/* File: OnlyConnect.cpp
 *
 * When dealing with recursion, it is crucial to consider the base case first. In our scenario, the
 * base case occurs when the input string is empty. In this case, we can immediately return an empty
 * string, which marks the termination point of our recursion.
 *
 * Next, let's address the normal scenario. Our goal is to remove non-letter and vowel characters, and
 * then convert the remaining non-vowel letters to uppercase. We should break down the phrase into smaller
 * segments until it becomes empty, following the principles of recursion, which align with our first critical
 * condition.
 *
 * So, how do we split and reduce the phrase? My proposed solution is to divide the phrase into two parts:
 * the last character and the rest of the phrase. By removing the last character, we can make the problem
 * smaller. It's essential to record the last character since it will be a non-vowel letter. Here, we encounter
 * two possible critical conditions:
 * 1. If the last character is a non-letter or a vowel character, there's no need to concatenate it back to the phrase.
 * Instead, we pass the modified phrase into the recursion.
 * 2. If the last character is a non-vowel letter, we convert it to uppercase and then append it back to the phrase.
 * We then pass the updated phrase, including the last character, into the recursion.
 *
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
#include "stdlib.h"
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string onlyConnectize(string phrase) {
    if (phrase.empty()) {
        return "";
    }

    char lastChar = phrase.back();
    phrase.pop_back();

    if (!isalpha(lastChar) || isVowel(lastChar)) {
        return onlyConnectize(phrase);
    } else {
        lastChar = toUpperCase(lastChar);
        return onlyConnectize(phrase) + lastChar;
    }
}






/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

STUDENT_TEST("My test case.") {
    EXPECT_EQUAL(onlyConnectize(""), "");
}






