from collections import Counter

# Class to perform statistical calculations on a list of integers
# This class includes methods to calculate mean, median, and mode
class StatisticsCalculator:
    # Initialize the class with the dataset (list of integers)
    def __init__(self, data):
        self.data = data

    # Method to calculate the mean of the list of integers
    def calculate_mean(self):
        # Sum all elements and divide by the number of elements
        return sum(self.data) / len(self.data)

    # Method to calculate the median of the list of integers
    def calculate_median(self):
        # Sort the dataset in ascending order
        sorted_data = sorted(self.data)

        n = len(sorted_data)
        mid = n // 2

        if n % 2 == 0:
            # If length of list is even, return the average of the two middle numbers
            return (sorted_data[mid - 1] + sorted_data[mid]) / 2
        else:
            # If length of list is odd, return the middle number
            return sorted_data[mid]

    # Method to calculate the mode of the list of integers
    def calculate_mode(self):
        # Count the frequency of each element in the dataset
        freq = Counter(self.data)
        # Find the maximum frequency
        max_freq = max(freq.values())
        # Find all numbers that have the maximum frequency
        modes = [num for num, count in freq.items() if count == max_freq]
        if max_freq == 1:
            return []
        return modes

# Main function with an example
if __name__ == "__main__":
    data = [10, 13, 22, 34, 22, 35, 13, 13]
    if not data:  # Check if the list is empty
        print("Enter a non-empty array for computations\n")
    else:
        stats = StatisticsCalculator(data)

        print(f"Data: {data}\n")
        print(f"Mean: {stats.calculate_mean():.2f}")
        print(f"Median: {stats.calculate_median():.2f}")
        mode_result = stats.calculate_mode()
        if not mode_result:
            print("Mode: No mode (all values are unique)")
        else:
            print(f"Mode: {' '.join(map(str, mode_result))}")