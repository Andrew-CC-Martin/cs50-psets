from cs50 import get_string

punctuation = ['.', '!', '?']

text = get_string("Text: ").split()

words = len(text)
letters = 0
sentences = 0

for word in text:
    for char in word:
        if char.isalpha():
            letters += 1
    if word[-1] in punctuation:
        sentences += 1

grade = int(round(((5.88 * letters - 29.6 * sentences) / words) - 15.8))
if grade < 1:
    print("Before Grade 1")
elif grade > 15:
    print("Grade 16+")
else:
    print("Grade ", grade)
