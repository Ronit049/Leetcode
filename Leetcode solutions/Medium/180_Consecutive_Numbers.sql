# Write your MySQL query statement below
select distinct l1.num as ConsecutiveNums 
from Logs l1 join Logs l2
on l2.id = l1.id+1
join Logs l3 
on l3.id = l1.id+2
where l1.num = l2.num
and l2.num = l3.num;