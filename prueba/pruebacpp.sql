--
-- PostgreSQL database dump
--

-- Dumped from database version 9.3.10
-- Dumped by pg_dump version 9.3.10
-- Started on 2018-08-09 23:28:36 -04

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

--
-- TOC entry 174 (class 3079 OID 11829)
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: -
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- TOC entry 2033 (class 0 OID 0)
-- Dependencies: 174
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: -
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = public, pg_catalog;

--
-- TOC entry 181 (class 1255 OID 1232269)
-- Name: unknown2text(unknown); Type: FUNCTION; Schema: public; Owner: -
--

CREATE FUNCTION unknown2text(unknown) RETURNS text
    LANGUAGE plpgsql
    AS $_$ begin return text($1::char); end $_$;


SET search_path = pg_catalog;

--
-- TOC entry 1829 (class 2605 OID 1232270)
-- Name: CAST (unknown AS text); Type: CAST; Schema: pg_catalog; Owner: -
--

CREATE CAST (unknown AS text) WITH FUNCTION public.unknown2text(unknown) AS IMPLICIT;


SET search_path = public, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 171 (class 1259 OID 1240718)
-- Name: profesor; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE profesor (
    id bigint NOT NULL,
    nombre character varying(20)
);


--
-- TOC entry 170 (class 1259 OID 1240716)
-- Name: profesor_id_seq; Type: SEQUENCE; Schema: public; Owner: -
--

CREATE SEQUENCE profesor_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- TOC entry 2034 (class 0 OID 0)
-- Dependencies: 170
-- Name: profesor_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: -
--

ALTER SEQUENCE profesor_id_seq OWNED BY profesor.id;


--
-- TOC entry 173 (class 1259 OID 1240732)
-- Name: tipocancelacion; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE tipocancelacion (
    id bigint NOT NULL,
    nombre character varying(20)
);


--
-- TOC entry 172 (class 1259 OID 1240730)
-- Name: tipocancelacion_id_seq; Type: SEQUENCE; Schema: public; Owner: -
--

CREATE SEQUENCE tipocancelacion_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- TOC entry 2035 (class 0 OID 0)
-- Dependencies: 172
-- Name: tipocancelacion_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: -
--

ALTER SEQUENCE tipocancelacion_id_seq OWNED BY tipocancelacion.id;


--
-- TOC entry 1909 (class 2604 OID 1240721)
-- Name: id; Type: DEFAULT; Schema: public; Owner: -
--

ALTER TABLE ONLY profesor ALTER COLUMN id SET DEFAULT nextval('profesor_id_seq'::regclass);


--
-- TOC entry 1910 (class 2604 OID 1240735)
-- Name: id; Type: DEFAULT; Schema: public; Owner: -
--

ALTER TABLE ONLY tipocancelacion ALTER COLUMN id SET DEFAULT nextval('tipocancelacion_id_seq'::regclass);


--
-- TOC entry 2023 (class 0 OID 1240718)
-- Dependencies: 171
-- Data for Name: profesor; Type: TABLE DATA; Schema: public; Owner: -
--

INSERT INTO profesor VALUES (2, 'Pedro Mago');
INSERT INTO profesor VALUES (1, 'Pedro Mago');


--
-- TOC entry 2036 (class 0 OID 0)
-- Dependencies: 170
-- Name: profesor_id_seq; Type: SEQUENCE SET; Schema: public; Owner: -
--

SELECT pg_catalog.setval('profesor_id_seq', 1, false);


--
-- TOC entry 2025 (class 0 OID 1240732)
-- Dependencies: 173
-- Data for Name: tipocancelacion; Type: TABLE DATA; Schema: public; Owner: -
--

INSERT INTO tipocancelacion VALUES (3, 'ZZZZZZZZZZZZZZZZZz');
INSERT INTO tipocancelacion VALUES (1, 'ZZZZZZZZZZZZZZZZZz');


--
-- TOC entry 2037 (class 0 OID 0)
-- Dependencies: 172
-- Name: tipocancelacion_id_seq; Type: SEQUENCE SET; Schema: public; Owner: -
--

SELECT pg_catalog.setval('tipocancelacion_id_seq', 1, false);


--
-- TOC entry 1912 (class 2606 OID 1240723)
-- Name: profesor_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY profesor
    ADD CONSTRAINT profesor_pkey PRIMARY KEY (id);


--
-- TOC entry 1914 (class 2606 OID 1240737)
-- Name: tipocancelacion_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY tipocancelacion
    ADD CONSTRAINT tipocancelacion_pkey PRIMARY KEY (id);


--
-- TOC entry 2032 (class 0 OID 0)
-- Dependencies: 5
-- Name: public; Type: ACL; Schema: -; Owner: -
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


-- Completed on 2018-08-09 23:28:37 -04

--
-- PostgreSQL database dump complete
--

