

def fractional_knapsack(weights, profits, capacity):
    n = len(weights)
    ratio = [(profits[i] / weights[i], weights[i], profits[i]) for i in range(n)]
    ratio.sort(reverse=True, key=lambda x: x[0])
    total_profit = 0
    remaining_capacity = capacity

    print("\nSelected Parcels:")
    for r, w, p in ratio:
        if remaining_capacity >= w:
            remaining_capacity -= w
            total_profit += p
            print(f"Weight: {w}, Profit: {p}, Taken: 100%")
        else:
            fraction = remaining_capacity / w
            total_profit += p * fraction
            print(f"Weight: {w}, Profit: {p}, Taken: {fraction * 100:.2f}%")
            break
    return total_profit


n = int(input("Enter number of parcels:"))
weights = []
profits = []

for i in range(n):
    weights.append(float(input(f"Enter weight of parcel {i+1}: ")))
    profits.append(float(input(f"Enter profit of parcel {i+1}: ")))

capacity = float(input("Enter truck capacity: "))

max_profit = fractional_knapsack(weights, profits, capacity)
print(f"\nMaximum Profit = {max_profit:.2f}")
