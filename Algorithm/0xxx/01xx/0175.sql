/* Write your T-SQL query statement below */
select firstName, lastName, ad.city, ad.state
from Person as p
left join Address as ad on p.personId = ad.personId
