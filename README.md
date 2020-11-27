# cs50_redability_buggy
buggy version of readability to ask for help

Error: :( handles questions in passage

Cause expected "Grade 2\n", not "Grade 3\n"

Actual output ~/pset2/readability/ $ ./readability -d "Would you like them here or there? I would not like them here or there. I would not like them anywhere." stats for nerds: 81 letters 21 words & 3 sentenes L = 81.00 ÷ 21.00 × 100 = 385.71 S = 3.00 ÷ 21.00 × 100 = 14.29 index = 0.0588 * 385.7143 - 0.296 * 14.2857 - 15.8 = 2.6514 rounded to 3 Grade 3

Manual analysis 1 2 3 4 5 6 7 V8 9 123456789012345678901234567890123456789012345678901234567890123456789012345678901 (80 letters, output 81) WouldyoulikethemhereorthereIwouldnotlikethemhereorthereIwouldnotlikethemanywhere 1 2 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 Would you like them here or there? I would not like them here or there. I would not like them anywhere.

Error :( handles single sentence with multiple words

Cause expected "Grade 7\n", not "Grade 8\n"

Actual output ~/pset2/readability/ $ ./readability -d "In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since." stats for nerds: 97 letters 23 words & 1 sentenes L = 97.00 ÷ 23.00 × 100 = 421.74 S = 1.00 ÷ 23.00 × 100 = 4.35 index = 0.0588 * 421.7391 - 0.296 * 4.3478 - 15.8 = 7.7113 rounded to 8 Grade 8

Manual analysis 1 2 3 4 5 6 7 8 9 V 1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890 InmyyoungerandmorevulnerableyearsmyfathergavemesomeadvicethatI'vebeenturningoverinmymindeversince (97 letters) 1 2 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 (23 words) In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.
