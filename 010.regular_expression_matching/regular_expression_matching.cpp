//============================================================================
// Name        : 10. Regular Expression Matching
// Author      : xing.zhongliang
// Version     :
// Copyright   : Your copyright notice
// Description : Leet Code question 10. Regular Expression Matching
// Accepted Date: 2017/09/04
/*****************************************************************************
 Implement regular expression matching with support for '.' and '*'.
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.

 The matching should cover the entire input string (not partial).

 The function prototype should be:
 bool isMatch(const char *s, const char *p)

 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "a*") → true
 isMatch("aa", ".*") → true
 isMatch("ab", ".*") → true
 isMatch("aab", "c*a*b") → true
 ******************************************************************************/
//============================================================================
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct rec
{
    string::const_iterator start;
    string::const_iterator off;
    char pat;
    bool isWild;
    bool isMulti;
    string::const_iterator next_pat;

    rec(string::const_iterator start_, string::const_iterator off_,
            char pat_, bool isWild_, bool isMulti_, string::const_iterator next_)
    :
            start(start_), off(off_), pat(pat_), isWild(isWild_), isMulti(isMulti_), next_pat(next_)
    {
    }
};

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<rec> stk;
        auto s_iter_1 = s.cbegin();
        auto s_iter_2 = s.cbegin();
        auto p_iter = p.cbegin();
        while (p_iter != p.cend())
        {
            // push current pattern in pattern stack
            if (p_iter + 1 != p.cend() && *(p_iter + 1) == '*')
            {
                stk.emplace_back(s.cend(), s.cend(), *p_iter, *p_iter == '.', true, p_iter + 2);
            }
            else
            {
                stk.emplace_back(s.cend(), s.cend(), *p_iter, *p_iter == '.', false, p_iter + 1);
            }

            rec *curPat = &stk.back();
            if (curPat->isMulti)
            {
                // multi pattern
                if (curPat -> isWild)
                {
                    curPat -> start = s_iter_1;
                    curPat -> off = s.cend();
                    s_iter_1 = s.cend();
                }
                else
                {
                    s_iter_2 = s_iter_1;
                    while (s_iter_2 != s.cend() && *s_iter_2 == curPat->pat)
                    {
                        ++s_iter_2;
                    }
                    curPat->start = s_iter_1;
                    curPat->off = s_iter_2;
                    s_iter_1 = s_iter_2;
                }
                p_iter = curPat->next_pat;
            }
            else
            {
                // signle pattern
                if (s_iter_1 < s.cend() && (curPat->isWild || *s_iter_1 == curPat->pat))
                {
                    ++s_iter_1;
                    p_iter = curPat->next_pat;
                }
                else
                {
                    stk.pop_back();
                    while (stk.size() > 0)
                    {
                        curPat = &stk.back();
                        p_iter = curPat->next_pat;
                        if (curPat->isMulti && curPat->start < curPat->off)
                        {
                            s_iter_1 = --(curPat->off);
                            break;
                        }
                        s_iter_1 = curPat->start;
                        stk.pop_back();
                    }
                    if (stk.size() == 0)
                        return false;
                }
            }
        }
        return s_iter_1 == s.cend();
    }
};

int main(int argc, char **argv)
{
    string str, pat;
    cout << "Inpute the string:" << endl;
    getline(cin, str);
    cout << "Inpute the Regular Expresspion:" << endl;
    getline(cin, pat);
    cout << "result: " << Solution().isMatch(str, pat) << endl;
    return EXIT_SUCCESS;
}

