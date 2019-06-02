n = int(input())
fact = [1]
for i in range(2 * n + 5):
    fact.append(fact[-1] * (i + 1))
print (fact[2 * (n + 1)] // fact[n + 1] // fact[n + 1] // (n + 2))