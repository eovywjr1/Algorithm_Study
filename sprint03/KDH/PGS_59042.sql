SELECT ANIMAL_OUTS.ANIMAL_ID, ANIMAL_OUTS.NAME 
FROM ANIMAL_OUTS 
WHERE ANIMAL_OUTS.ANIMAL_ID NOT IN (SELECT ANIMAL_ID FROM ANIMAL_INS)