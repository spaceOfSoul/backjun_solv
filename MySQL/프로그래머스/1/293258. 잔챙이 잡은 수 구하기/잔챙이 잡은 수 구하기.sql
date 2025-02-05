select count(ID) as FISH_COUNT
from FISH_INFO 
where ifnull(LENGTH,0) <= 10.0