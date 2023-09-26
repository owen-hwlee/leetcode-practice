# Write your MySQL query statement below
SELECT Employee.name as Employee
FROM Employee
INNER JOIN Employee as Manager
ON Employee.managerId = Manager.id
WHERE Employee.salary > Manager.salary;