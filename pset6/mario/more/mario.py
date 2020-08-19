from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

counter = height - 1
for i in range(height):
    hashes = '#' * (i + 1)
    print(f"{' ' * counter}{hashes}  {hashes}")
    counter -= 1