# language: en

Feature: fizz_buzz_reporter
  In order to practice for programming interviews
  As someone who is bad at the fizz buzz exercise
  I want to be told whether an unsigned integer corresponds to fizz, buzz, or fizzbuzz

#  Scenario Outline: Report the fizzbuzz string associated with an integer
  Scenario Outline: Add two numbers
    Given I have passed <input> into fizz_buzz_reporter
    Then the result should be <output>

  Examples:
  | input | output   |
  | 3     | FIZZ     |
  | 5     | BUZZ     |
  | 15    | FIZZBUZZ |
  | 11    | 11       |
