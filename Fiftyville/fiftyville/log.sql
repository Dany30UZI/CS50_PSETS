-- Keep a log of any SQL queries you execute as you solve the mystery.

--Am descoperit ora la care a avut loc jaful si cati marotir au fost.
SELECT description
FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2023 AND street = 'Humphrey Street';

--Amd descoperit numele celor 3 martori + parcarea de unde a plecat + unde a fost vazut + plecare Fiftyville.
SELECT transcript, name
FROM interviews
WHERE day = 28 AND month = 7 AND year = 2023;

--Masini posbilile
SELECT activity, license_plate, hour, minute
FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2023 AND hour = 10;

--Tranzactiile din ziua respectiva
SELECT account_number, transaction_type, amount, day
FROM atm_transactions
WHERE atm_location = 'Leggett Street' AND year = 2023 AND day = 28 AND month = 7;

--Conexiunile dintre conturile care au scos banni de la ATM
SELECT name, phone_number, passport_number, license_plate
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_location = 'Leggett Street' AND year = 2023 AND day = 28 AND month = 7;

--Telefoane- am redus suspectii la doi si am gasit 2 posibili complici
SELECT caller, receiver, duration
FROM phone_calls
WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60;

-- Afla persoana de la telefon Diana
SELECT name, passport_number
FROM people
WHERE phone_number = '(725) 555-3243';

-- Afla persoana de la telefon Taylor
SELECT name, passport_number
FROM people
WHERE phone_number = '(676) 555-6554';

--Locuri pasageri
SELECT flight_id, seat
FROM passengers
WHERE passport_number = 2438825627;

-- Aeroport
SELECT abbreviation, full_name
FROM airports
WHERE city = 'Fiftyville';

--Zboruri
SELECT abbreviation, full_name, city
FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
JOIN passengers ON flights.id = passengers.flight_id
WHERE passport_number = 2438825627;

