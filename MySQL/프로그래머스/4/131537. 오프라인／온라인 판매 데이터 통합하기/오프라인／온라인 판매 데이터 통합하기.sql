-- 코드를 입력하세요
select 
DATE_FORMAT(SALES_DATE,'%Y-%m-%d') as SALES_DATE, 
PRODUCT_ID, 
USER_ID, 
SALES_AMOUNT
from
(
(select SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT
 from ONLINE_SALE)
union
(select SALES_DATE, PRODUCT_ID, NULL as USER_ID, SALES_AMOUNT
 from OFFLINE_SALE)
) as sales
where SALES_DATE between '2022-03-01' and '2022-03-31'
order by 
SALES_DATE asc, 
PRODUCT_ID asc, 
USER_ID asc;