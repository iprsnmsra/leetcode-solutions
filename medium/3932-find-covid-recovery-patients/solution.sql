-- Step 1: Find the earliest Positive test date for each patient
WITH FirstPositive AS (
    SELECT 
        patient_id, 
        MIN(test_date) AS first_pos_date
    FROM covid_tests
    WHERE result = 'Positive'
    GROUP BY patient_id
),

-- Step 2: Find the earliest Negative test date that occurs AFTER the first Positive test
FirstNegativeAfterPositive AS (
    SELECT 
        c.patient_id, 
        MIN(c.test_date) AS first_neg_date
    FROM covid_tests c
    JOIN FirstPositive fp ON c.patient_id = fp.patient_id
    WHERE c.result = 'Negative' 
      AND c.test_date > fp.first_pos_date
    GROUP BY c.patient_id
)

-- Step 3: Combine with patient details, calculate the difference, and sort
SELECT 
    p.patient_id,
    p.patient_name,
    p.age,
    DATEDIFF(fn.first_neg_date, fp.first_pos_date) AS recovery_time
FROM patients p
JOIN FirstPositive fp ON p.patient_id = fp.patient_id
JOIN FirstNegativeAfterPositive fn ON p.patient_id = fn.patient_id
ORDER BY 
    recovery_time ASC, 
    p.patient_name ASC;