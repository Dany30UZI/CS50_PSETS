from cs50 import get_string
import re


countl = 0
countb = 0
count_sem = 0
cuvinte = 0
index = 0.0

text = get_string("Text: ")
length = len(text)

for i in range(length):
    if str.isalpha(text[i]):
        countl += 1
    elif bool(re.search(r"\s", text[i])) == True:
        countb += 1
    elif text[i] == '!' or text[i] == '?' or text[i] == '.':
        count_sem += 1


cuvinte = countb + 1

index = 0.0588 * (100.0 * countl / cuvinte) - 0.296 * (100.0 * count_sem / cuvinte) - 15.8

x = int(round(index))

if x < 1:
    print("Before Grade 1")
elif x >= 16:
    print("Grade 16+")
else:
    print(f"Grade {x}")
