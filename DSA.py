def get_student_marks(n):
    marks = []
    for i in range(n):
        while True:
            mark = input(f"Enter the mark for student {i+1} (or type 'A' if absent): ")
            if mark.lower() == 'a':
                marks.append(None)  # None represents an absent student
                break
            try:
                mark = float(mark)
                if 0 <= mark <= 100:  # assuming marks are between 0 and 100
                    marks.append(mark)
                    break
                else:
                    print("Please enter a valid mark between 0 and 100.")
            except ValueError:
                print("Please enter a valid number or 'A' for absent.")
    return marks

def compute_average(marks):
    valid_marks = [mark for mark in marks if mark is not None]
    if valid_marks:
        return sum(valid_marks) / len(valid_marks)
    return 0

def find_highest_lowest(marks):
    valid_marks = [mark for mark in marks if mark is not None]
    if valid_marks:
        return max(valid_marks), min(valid_marks)
    return None, None

def count_absent_students(marks):
    return marks.count(None)

def highest_frequency_mark(marks):
    from collections import Counter
    valid_marks = [mark for mark in marks if mark is not None]
    if valid_marks:
        mark_freq = Counter(valid_marks)
        max_freq = max(mark_freq.values())
        most_frequent_marks = [mark for mark, freq in mark_freq.items() if freq == max_freq]
        return most_frequent_marks, max_freq
    return None, 0

def main():
    n = int(input("Enter the number of students: "))
    marks = get_student_marks(n)
    
    avg_score = compute_average(marks)
    highest_score, lowest_score = find_highest_lowest(marks)
    absent_count = count_absent_students(marks)
    most_frequent_marks, max_freq = highest_frequency_mark(marks)
    
    print("\nClass Statistics:")
    print(f"Average score: {avg_score:.2f}")
    if highest_score is not None and lowest_score is not None:
        print(f"Highest score: {highest_score}")
        print(f"Lowest score: {lowest_score}")
    else:
        print("No scores available to determine highest and lowest scores.")
    print(f"Number of students absent: {absent_count}")
    if most_frequent_marks:
        print(f"Marks with highest frequency ({max_freq} times): {', '.join(map(str, most_frequent_marks))}")
    else:
        print("No marks available to determine frequency.")

if __name__ == "__main__":
    main()
