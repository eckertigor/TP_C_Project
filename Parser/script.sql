-- MySQL dump 10.13  Distrib 5.7.12, for Linux (i686)
--
-- Host: 127.0.0.1    Database: appDB
-- ------------------------------------------------------
-- Server version	5.7.12-0ubuntu1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `place`
--

DROP TABLE IF EXISTS `place`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `place` (
  `place_id` int(11) NOT NULL AUTO_INCREMENT,
  `place_name` varchar(45) NOT NULL,
  `place_weather` int(11) DEFAULT NULL COMMENT '\n\n\n',
  `place_activity` int(11) DEFAULT NULL,
  PRIMARY KEY (`place_id`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `place`
--

LOCK TABLES `place` WRITE;
/*!40000 ALTER TABLE `place` DISABLE KEYS */;
INSERT INTO `place` VALUES (6,'Москва',30,4),(7,'Балашиха',5,1),(8,'Берлин',15,2),(9,'Оймякон',-30,2),(10,'Зеленоград',0,3),(11,'Рим',10,4),(12,'Монако',40,5),(13,'Осло',-3,6),(14,'Афины',17,7);
/*!40000 ALTER TABLE `place` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `place_description`
--

DROP TABLE IF EXISTS `place_description`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `place_description` (
  `descr_id` int(11) NOT NULL AUTO_INCREMENT,
  `descr_place` int(11) NOT NULL,
  `descr_about` varchar(250) DEFAULT NULL,
  `descr_logo` varchar(45) DEFAULT NULL,
  `descr_activity` varchar(45) DEFAULT NULL,
  `descr_food` varchar(45) DEFAULT NULL,
  `descr_language` varchar(45) DEFAULT NULL,
  `descr_money` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`descr_id`),
  KEY `fk_place_description_1` (`descr_place`),
  CONSTRAINT `fk_place_description_1` FOREIGN KEY (`descr_place`) REFERENCES `place` (`place_id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `place_description`
--

LOCK TABLES `place_description` WRITE;
/*!40000 ALTER TABLE `place_description` DISABLE KEYS */;
/*!40000 ALTER TABLE `place_description` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tag_pars`
--

DROP TABLE IF EXISTS `tag_pars`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tag_pars` (
  `id_tag` int(11) NOT NULL,
  `tag_begin` varchar(45) DEFAULT NULL,
  `tag_end` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id_tag`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tag_pars`
--

LOCK TABLES `tag_pars` WRITE;
/*!40000 ALTER TABLE `tag_pars` DISABLE KEYS */;
INSERT INTO `tag_pars` VALUES (1,'type_now\">','°');
/*!40000 ALTER TABLE `tag_pars` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `weather_url_now`
--

DROP TABLE IF EXISTS `weather_url_now`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `weather_url_now` (
  `place_id` int(11) NOT NULL,
  `url_parser` varchar(45) DEFAULT NULL,
  `id_tag` int(11) DEFAULT NULL,
  PRIMARY KEY (`place_id`),
  KEY `fk_weather_url_now_2_idx` (`id_tag`),
  CONSTRAINT `fk_weather_url_now_1` FOREIGN KEY (`place_id`) REFERENCES `place` (`place_id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_weather_url_now_2` FOREIGN KEY (`id_tag`) REFERENCES `tag_pars` (`id_tag`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `weather_url_now`
--

LOCK TABLES `weather_url_now` WRITE;
/*!40000 ALTER TABLE `weather_url_now` DISABLE KEYS */;
INSERT INTO `weather_url_now` VALUES (6,'https://pogoda.yandex.ru/moscow',1),(7,'https://pogoda.yandex.ru/balashiha',1),(8,'https://pogoda.yandex.ru/berlin',1),(9,'https://pogoda.yandex.ru/11438',1),(10,'https://pogoda.yandex.ru/216',1),(11,'https://pogoda.yandex.ru/10445',1),(12,'https://pogoda.yandex.ru/10465',1),(13,'https://pogoda.yandex.ru/10467',1),(14,'https://pogoda.yandex.ru/10418',1);
/*!40000 ALTER TABLE `weather_url_now` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-05-10  0:39:19
