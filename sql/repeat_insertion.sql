/*
 * Shows how we can use [anonymous code block](https://www.postgresql.org/docs/9.0/sql-do.html)
 * to repeatedly insert rows (e.g., 5 times) into table named `bench`
 *
 * Tested on: PostgreSQL
 *
 * Usage: psql < repeat_insertion.sql
 */
DROP TABLE IF EXISTS bench;

CREATE TABLE bench(
    theKey INT PRIMARY KEY,
    columnA INT,
    columnB INT,
    filler CHAR(247)
);

DO $$
BEGIN
   FOR counter IN 1..5 LOOP
   INSERT INTO bench(theKey, columnA, columnB, filler)
   VALUES(counter,counter,counter,'asd');
   END LOOP;
END$$;
