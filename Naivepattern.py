text = input("Enter the text: ")
pattern = input("Enter the pattern to search: ")

n = len(text)
m = len(pattern)
found = False

for i in range(n - m + 1):
    j = 0
    while j < m and text[i + j] == pattern[j]:
        j += 1
    if j == m:
        print("\nPattern found at positions:")
        print(f"Pattern found at index {i}")
        found = True

if not found:
    print("No pattern match found in given string.")
