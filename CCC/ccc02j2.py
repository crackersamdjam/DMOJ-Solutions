vowel = "aeiouy"
while 1:
    s = input()
    if s == "quit!":
        break
    if len(s) >= 4 and s.endswith("or") and s[len(s)-3] not in vowel:
        s = s[:len(s)-2] + "our"
    print(s)