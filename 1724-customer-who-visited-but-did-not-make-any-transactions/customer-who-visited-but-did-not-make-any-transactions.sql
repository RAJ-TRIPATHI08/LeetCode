# Write your MySQL query statement below
Select
    v.customer_id, COUNT(v.visit_id)
As
    count_no_trans
From
    Visits v
Left Join
    Transactions t
On 
    v.visit_id = t.visit_id
Where 
    t.transaction_id is NULL
Group By
    v.customer_id;