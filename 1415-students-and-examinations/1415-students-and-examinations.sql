# Write your MySQL query statement below

# SELECT Students.student_id, student_name, Subjects.subject_name, COUNT(Examinations.student_id) AS attended_exams
# FROM Students
# CROSS JOIN Subjects
# LEFT JOIN Examinations
# ON Students.student_id = Examinations.student_id AND Subjects.subject_name = Examinations.subject_name
# GROUP BY Students.student_id, Subjects.subject_name
# ORDER BY student_id, subject_name;

SELECT Students.student_id, student_name, Subjects.subject_name, IFNULL(attended_exams, 0) AS attended_exams
FROM Students
CROSS JOIN Subjects
LEFT JOIN (
    SELECT student_id, subject_name, COUNT(*) AS attended_exams
    FROM Examinations
    GROUP BY student_id, subject_name
) e USING (student_id, subject_name)
ORDER BY student_id, subject_name;
