wordbook = {'red':'SSS', 'blue':'FFF', 'green':'MMM' }

S = input().strip()

print(wordbook[S] if S in wordbook else "Unknown")

