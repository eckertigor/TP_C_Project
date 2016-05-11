CREATE DATABASE `appDB` /*!40100 DEFAULT CHARACTER SET latin1 */;

CREATE TABLE `appDB`.`place` (
  `place_id` int(11) NOT NULL AUTO_INCREMENT,
  `place_name` varchar(45) NOT NULL,
  `place_weather` int(11) DEFAULT NULL COMMENT '\n\n\n',
  `place_activity` int(11) DEFAULT NULL,
  PRIMARY KEY (`place_id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARACTER SET utf8;

CREATE TABLE `appDB`.`place_description` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `place` INT NOT NULL,
  `about` VARCHAR(250) NULL,
  `logo` VARCHAR(45) NULL,
  `activity` VARCHAR(45) NULL,
  `food` VARCHAR(45) NULL,
  `language` VARCHAR(45) NULL,
  `money` VARCHAR(45) NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `fk_place_description_1`
    FOREIGN KEY (`place`)
    REFERENCES `appDB`.`place` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);

ALTER table place_description CONVERT TO CHARACTER SET utf8;


ALTER table place CONVERT TO CHARACTER SET utf8;


INSERT INTO appDB.place (place_name, place_weather, place_activity)
 VALUES ('Moscow', +30, 4), ('Balashiha', +5, 1), ('Berlin', +15, 2), ('Huliduli', -30, 2),
 ('Greengrad', 0 , 3), ('Rome', +10, 4), ('Mokako', +40, 5), ('Oslo', -3, 6),
 ('Afina', +17, 7);



INSERT INTO appDB.place_description (place, about, logo, activity, food, language, money)
 VALUES
(1, 'Success history 1', 'htttp://logo1/', 'Description1', 'tasty food, meat, shaverma, blini', 'English, Russian', 'Euro'),
(1, 'Success history 1', 'htttp://logo1/', 'Description1', 'tasty food, meat, shaverma, blini', 'English, Russian', 'Euro'),
(1, 'Success history 1', 'htttp://logo1/', 'Description1', 'tasty food, meat, shaverma, blini', 'English, Russian', 'Euro'),
(1, 'Success history 1', 'htttp://logo1/', 'Description1', 'tasty food, meat, shaverma, blini', 'English, Russian', 'Euro'),
(1, 'Success history 1', 'htttp://logo1/', 'Description1', 'tasty food, meat, shaverma, blini', 'English, Russian', 'Euro'),
(1, 'Success history 1', 'htttp://logo1/', 'Description1', 'tasty food, meat, shaverma, blini', 'English, Russian', 'Euro'),
(1, 'Success history 1', 'htttp://logo1/', 'Description1', 'tasty food, meat, shaverma, blini', 'English, Russian', 'Euro'),
(1, 'Success history 1', 'htttp://logo1/', 'Description1', 'tasty food, meat, shaverma, blini', 'English, Russian', 'Euro'),
(1, 'Success history 1', 'htttp://logo1/', 'Description1', 'tasty food, meat, shaverma, blini', 'English, Russian', 'Euro'),
(1, 'Success history 1', 'htttp://logo1/', 'Description1', 'tasty food, meat, shaverma, blini', 'English, Russian', 'Euro'),
(1, 'Success history 1', 'htttp://logo1/', 'Description1', 'tasty food, meat, shaverma, blini', 'English, Russian', 'Euro'),
(1, 'Success history 1', 'htttp://logo1/', 'Description1', 'tasty food, meat, shaverma, blini', 'English, Russian', 'Euro');


