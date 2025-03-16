def number_spiral(t, queries):
    results = []
    for y, x in queries:
        if y >= x:
            if y % 2 == 1:
                results.append(y**2 - x + 1)
            else:
                results.append((y-1)**2 + x)
        else:
            if x % 2 == 1:
                results.append((x-1)**2 + y)
            else:
                results.append(x**2 - y + 1)
    return results

# Read input
t = int(input())
queries = [tuple(map(int, input().split())) for _ in range(t)]

# Compute results and print
for result in number_spiral(t, queries):
    print(result)
