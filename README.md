# Word and URL Analyzer

A simple C++ console application that processes a text file (`text.txt`) to:
- Count and list repeating words (with counts and line numbers)
- Extract URLs (full or abbreviated) and save them separately

## Featuress
- Creates a formatted table of every word occurring more than once, with its count and line numbers where it repeats. Outputs in `urls_out.txt`
- Scans the raw file content for web addresses, including: `http://…`, `https://…`, `www`, domains with common TLDs (`cool.lt`, `site.de`, `mysite.ai`). Outputs in `words_out.txt`

## How to Use
1. Ensure `text.txt` is placed in the same folder as the main.exe.
2. Run the program and after it finishes, check the output files:
-  words_out.txt – table of repeated words, counts, and line numbers
-  urls_out.txt – list of extracted URLs

## Example 
`text.txt`
```
Check out our sites: www.example.com, cool.lt, and cool.de.  
To be, or not to be: that is the question.  
Visit https://docs.example.org/getting-started for more info.  
Whether ’tis nobler in the mind to suffer.  
The heart-ache and the thousand natural shocks.  
To die: to sleep; perchance to dream: ay, there’s the rub;    
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
