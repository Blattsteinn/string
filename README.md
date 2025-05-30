

This is basic C++ console application that processes a plain-text file (“text.txt”) to count repeating words.

It reads the entire file into memory, then strips punctuation and ignores single-letter abbreviations. The application then builds a map of each word’s total occurrences and the distinct line numbers on which it appears. As a result it prints a formatted table listing every word that occurs more than once, alongside its count and the lines where it’s found.

##  Example (text.txt)
```
1: To be, or not to be: that is the question.  
2: Whether ’tis nobler in the mind to suffer  
3: The slings and arrows of outrageous fortune,  
4: Or to take Arms against a sea of troubles,  
5: And by opposing end them: to die: to sleep;  
6: No more; and by a sleep to say we end  
7: The heart-ache and the thousand natural shocks  
8: That Flesh is heir to; ’tis a consummation  
9: Devoutly to be wish’d. To die, to sleep;  
10: To sleep: perchance to dream: ay, there’s the rub;  
```
## Results
```
Word           Count   Lines
------------   -----   ----------------
to             12      1, 2, 4, 5, 6, 8, 9, 10
be             3       1, 9
sleep          4       5, 6, 9, 10
die            2       5, 9
and            3       3, 6, 7
of             3       3, 4, 8
the            9       1, 2, 3, 7, 8, 9, 10
that           3       1, 7, 8
tis            2       2, 8
```
