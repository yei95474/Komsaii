The "Student Gradebook" Challenge

1. The Setup (The Struct)
   Create a struct named Student with:

string name

vector `<int>` scores (A vector inside a struct! This is a common midterm "Level 2" topic).

double average

2. Problem A: The "Data Entry" (Void Function)
   Write a function void addStudent(vector `<Student>` &classroom).

Logic: 1. Ask for the name.
2. Ask how many scores they want to input.
3. Use a loop to push_back those scores into the student's internal scores vector.
4. push_back the finished student into the classroom vector.

3. Problem B: The "Processor" (Reference Function)
   Write a function void calculateAverages(vector `<Student>` &classroom).

Logic: Use a nested loop (a loop inside a loop).

The outer loop goes through each Student in the classroom.

The inner loop sums up the scores vector inside that specific student.

Calculate the average and save it directly into that student's average member.

Why? This tests if you can navigate "Nested Data Structures" (a vector inside a struct inside a vector).

4. Problem C: The "Honor Roll" (Vector Return Function)
   Write a function vector `<string>` getHonorRoll(const vector `<Student>` &classroom, double threshold).

Logic: * Create a vector `<string>` namesOnly.

If a student's average is above the threshold, push_back only their name into the new vector.

Return: The vector of strings.
