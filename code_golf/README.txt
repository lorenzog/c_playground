http://stackoverflow.com/questions/1805796/code-golf-ulam-spiral

The Challenge
The shortest code by character count to output Ulam's spiral with a spiral
size given by user input.

Ulam's spiral is one method to map prime numbers. The spiral starts from the
number 1 being in the center (1 is not a prime) and generating a spiral
around it, marking all prime numbers as the character '*'. A non prime will be
printed as a space ' '.


--


my best result:

cat ulam_compr.c | sed 's/\t//g' | wc -c
332

(removing \n and \t)
