# Write your MySQL query statement below
select Person.FirstName,Person.LastName,Address.City,Address.State from Person LEFT JOIN Address ON Person.PersonID = Address.PersonID