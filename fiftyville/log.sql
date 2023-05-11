-- Keep a log of any SQL queries you execute as you solve the mystery.

-- look for the description of the crime scene report
-- SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";

 Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
| Littering took place at 16:36. No known witnesses.

-- look for the witnesses reports
SELECT name, transcript
   ...> FROM interviews
   ...> WHERE year = 2021
   ...> AND month = 7
   ...> AND day = 28;

   -- look for accounts that have been withdraws, the witnesses reports says that the thief made a withdraw
 SELECT account_number
  FROM atm_transactions
  WHERE year = 2021
   AND month = 7
   AND day = 28
   AND atm_location = 'Leggett Street'
   AND transaction_type = 'withdraw';

   -- look for the names of the accounts and get a list of suspects "Bruce, Diana, Brooke, Kenny, Iman, Luca, Taylor,Benista"
   SELECT name
   ...> FROM people
   ...> JOIN bank_accounts
   ...> ON people.id = bank_accounts.person_id
   ...> JOIN atm_transactions
   ...> ON bank_accounts.account_number = atm_transactions.account_number
   ...> WHERE atm_transactions.year = 2021
   ...> AND atm_transactions.month = 7
   ...> AND atm_transactions.day = 28
   ...> AND atm_transactions.atm_location = "Leggett Street"
   ...> AND atm_transactions.transaction_type ="withdraw";

   -- look for flights next morning coming out of fiftyville and matching
   SELECT flights.id, full_name, city, flights.hour, flights.minute
  FROM airports
  JOIN flights
    ON airports.id = flights.destination_airport_id
 WHERE flights.origin_airport_id =
       (SELECT id
          FROM airports
         WHERE city = 'Fiftyville')
   AND flights.year = 2021
   AND flights.month = 7
   AND flights.day = 29
 ORDER BY flights.hour, flights.minute;



-- checks the two flights of the next morning
SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat
  FROM people
  JOIN passengers
    ON people.passport_number = passengers.passport_number
  JOIN flights
    ON passengers.flight_id = flights.id
 WHERE flights.year = 2021
   AND flights.month = 7
   AND flights.day = 29
   AND flights.hour = 8
   AND flights.minute = 20
 ORDER BY passengers.passport_number;

 SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat
  FROM people
  JOIN passengers
    ON people.passport_number = passengers.passport_number
  JOIN flights
    ON passengers.flight_id = flights.id
 WHERE flights.year = 2021
   AND flights.month = 7
   AND flights.day = 29
   AND flights.hour = 9
   AND flights.minute = 30
 ORDER BY passengers.passport_number;

 -- the first flight has names within the suspect list

 -- now the list of suspects is "Bruce, kenny and luca"

-- checking phone calls, excludind luca from the suspect list (suspect list: bruce, kenny, taylor)
 SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.caller
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
 ORDER BY phone_calls.duration;


-- cheking who drove away from the bakery within 10 minutes.  only bruce of the suspect list appears
 SELECT name, bakery_security_logs.hour, bakery_security_logs.minute
  FROM people
  JOIN bakery_security_logs
    ON people.license_plate = bakery_security_logs.license_plate
 WHERE bakery_security_logs.year = 2021
   AND bakery_security_logs.month = 7
   AND bakery_security_logs.day = 28
   AND bakery_security_logs.activity = 'exit'
   AND bakery_security_logs.hour = 10
   AND bakery_security_logs.minute >= 15
   AND bakery_security_logs.minute <= 25
 ORDER BY bakery_security_logs.minute;

-- checking the duration of the call
SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.caller
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
 ORDER BY phone_calls.duration;

 -- the call matches robin
 SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.receiver
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
   ORDER BY phone_calls.duration;

   -- bruce is the thief and robin is the accomplice