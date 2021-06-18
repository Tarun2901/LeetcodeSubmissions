# Write your MySQL query statement below
select (case when id % 2 = 0 then id -1
when id % 2 !=0 and id = (select count(*) from seat) then id
else id +1 end) id , student
from seat s
order by id