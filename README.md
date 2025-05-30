

This is basic C++ console application that processes a plain-text file (“text.txt”) to count repeating words and check for url adresses.

## Featuress
- Creates a formatted table of every word occurring more than once, with its count and line numbers where it repeats. Outputs in `urls_out.txt`
- Scans the raw file content for web addresses, including: `http://…`, `https://…`, `www`, domains with common TLDs (`cool.lt`, `site.de`, `mysite.ai`). Outputs in `words_out.txt`


###  Example 
`text.txt`
```
1: Check out our sites: www.example.com, cool.lt, and cool.de.  
2: To be, or not to be: that is the question.  
3: Visit https://docs.example.org/getting-started for more info.  
4: Whether ’tis nobler in the mind to suffer.  
5: The heart-ache and the thousand natural shocks.  
6: To die: to sleep; perchance to dream: ay, there’s the rub;    
```
### Results
`words_out.txt`
```
Word           Count   Lines
------------   -----   ----------------
to             5       2, 4, 6
be             2       2
tis            1       4
the            4       2, 3, 5, 6
and            2       1, 5
```
`urls_out.txt`
```
www.example.com
cool.lt
cool.de
https://docs.example.org/getting-started
```
