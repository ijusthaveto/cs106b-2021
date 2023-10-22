#include "WhatAreYouDoing.h"
#include <cctype>
#include "strlib.h"
#include "hashmap.h"
using namespace std;

string vecToStr(Vector<string> & tokens) {
    string result = "";
    for (const string & token : tokens) {
        result += token;
    }
    return result;
}

void allEmphasesRec(Vector<string> tokens, Vector<int> & state, Set<string> & res, int wordCnt, int curIdx) {
    if (curIdx == tokens.size() - 1) {
        for (int i = 0; i < tokens.size(); ++i) {
            /* Verity the word */
            if (state[i] == 1) {
                tokens[i] = toUpperCase(tokens[i]);
            } else if (state[i] == 2) {
                tokens[i] = toLowerCase(tokens[i]);
            }
        }
        res.add(vecToStr(tokens));
        return;
    }

    while (curIdx < tokens.size() && !isalpha(tokens[curIdx][0])) {
        curIdx++;
    }

    state[curIdx] = 1;
    allEmphasesRec(tokens, state, res, wordCnt, curIdx + 1);

    state[curIdx] = 2;
    allEmphasesRec(tokens, state, res, wordCnt, curIdx + 1);
}


Set<string> allEmphasesOf(const string& sentence) {
    /* Split the sentence */
    Vector<string> tokens = tokenize(sentence);
    Vector<int> state(tokens.size() + 1, 0);

    int wordCnt = 0;
    for (string & token : tokens) {
        if (isalpha(token[0])) {
            token = toLowerCase(token);
            wordCnt++;
        }
    }

    /* Without English words */
    if (!wordCnt) {
        return {vecToStr(tokens)};
    } else if (wordCnt == 1) {
        return {toUpperCase(vecToStr(tokens)), toLowerCase(vecToStr(tokens))};
    }

    Set<string> res;
    allEmphasesRec(tokens, state, res, wordCnt, 0);

    return res;
}


/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

STUDENT_TEST("Test of my own.") {
    string sentence = "What a nice day!";
    EXPECT_EQUAL(allEmphasesOf(sentence).size(), 16);
}


/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Enumerates all options in a simple case.") {
    Set<string> expected = {
        "hello",
        "HELLO",
    };

    EXPECT_EQUAL(allEmphasesOf("Hello"), expected);
}

PROVIDED_TEST("Each option has the right length.") {
    string sentence = "Hello, world!";
    for (string option: allEmphasesOf(sentence)) {
        EXPECT_EQUAL(option.length(), sentence.length());
    }
}

PROVIDED_TEST("Enumerates all options in a more typical case.") {
    Set<string> expected = {
        "you are?",
        "you ARE?",
        "YOU are?",
        "YOU ARE?"
    };

    EXPECT_EQUAL(allEmphasesOf("You Are?"), expected);
}

PROVIDED_TEST("Stress Test: Recursion only branches on words (should take under a second)") {
    /* We're producing a string consisting of fifty copies of the * character. This tokenizes
     * into fifty separate stars. A star is the same whether or not you capitalize it - there
     * is no such thing as an "upper-case" or "lower-case" star. Therefore, your code should
     * not try to form two versions of the sentence, one with the star capitalized and one
     * without, because the two versions will end up being the same and the work to compute
     * both options will dramatically increase the runtime.
     *
     * For reference, if you do try branching the recursion and checking what happens both if
     * you capitalize the star and if you don't, you'll try exploring 2^50 different possible
     * capitalizations. That's 1,125,899,906,842,624 options, and even doing a billion of
     * these a second is going to take over two years to generate them all! And of course,
     * that's all wasted work, since there's only one way to capitalize this sentence, and
     * that's just to leave it as-is.
     *
     * If your code is hanging when this test is running, it likely means that your code is
     * trying to enumerate all of these options. See if you can edit your code so that, if
     * you're given a non-word token, you just leave it as-is and don't change anything.
     */
    string punctuation(50, '*'); // 50 copies of *

    /* The only emphasis is itself. */
    Set<string> expected = {
        punctuation
    };

    EXPECT_EQUAL(allEmphasesOf(punctuation), expected);
}

PROVIDED_TEST("Stress test: Generates each option once (should take at most a few seconds)") {
    /* This sentence has 13 words in it. There are therefore 2^13 = 8192 possible emphases for
     * the words there, which is a big number but not so large that the computer can't handle
     * it if generates each emphasis exactly once.
     *
     * On the other hand, if your code tries to generate the same emphases multiple times,
     * this test may take a very, very long time to complete, and might even appear to freeze
     * up.
     *
     * If your code gets stuck in this test, trace through your code and confirm that you can't
     * produce the same emphasis multiple times. Check to make sure you aren't, for example,
     * looping over every token in the input sentence and deciding which one to capitalize
     * next. The recursion here follows more of an include/exclude type pattern (more like
     * subsets and combinations) than it does a "which is next?" type pattern (more like
     * permutations).
     */
    string yeats = "Turing and turning in a widening gyre / the falcon cannot hear the falconer.";
    EXPECT_EQUAL(allEmphasesOf(yeats).size(), 8192);
}
