SELECT "[0-5>" AS BIN, COUNT(*) AS TOTAL FROM Sessions 
WHERE duration < 300
UNION
SELECT "[5-10>" AS BIN, COUNT(*) AS TOTAL FROM Sessions 
WHERE duration >= 300 AND duration < 600
UNION
SELECT "[10-15>" AS BIN, COUNT(*) AS TOTAL FROM Sessions 
WHERE duration >= 600 AND duration < 900
UNION
SELECT "15 or more" AS BIN, COUNT(*) AS TOTAL FROM Sessions 
WHERE duration >= 900;
