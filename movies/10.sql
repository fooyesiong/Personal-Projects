--SELECT distinct name FROM people, directors, ratings WHERE people.id = directors.person_id AND directors.movie_id = ratings.movie_id AND rating >= 9.0;
SELECT name FROM people
JOIN directors ON people.id = directors.person_id
JOIN ratings ON directors.movie_id = ratings.movie_id
WHERE ratings.rating >= 9.0;