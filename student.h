#ifndef __STUDENT_H
#define __STUDENT_H


#define STUDENT_OK 		0
#define STUDENT_MEM_ERROR 	1
#define STUDENT_NOT_FOUND 	2
#define STUDENT_CAN_NOT_REMOVE  3

typedef unsigned char student_ret_t;
typedef unsigned char student_bool_t;
typedef unsigned int student_base_t;

struct _student_base_info {
	unsigned char *name;
	student_base_t num;
};

struct _student_scores {
	float optional;
	float experimental;
	float required;
	float total;
};

struct _student_object {
	struct _student_base_info info;
	struct _student_scores scores;
};

typedef struct _student_object StudentAttribute;
typedef struct _student_object * StudentObject;
typedef struct _student_list * StudentList;

StudentList student_list_create(void);

void student_object_swap(StudentObject __restrict object0,
			 StudentObject __restrict object1);
void student_object_attr_export(StudentObject object,
				StudentAttribute *attr);
void student_object_modify(StudentObject object,
			   StudentAttribute *attr);
void student_object_scores_sum(StudentAttribute *attr);
student_base_t student_object_get_name_length(StudentObject object);


StudentObject student_list_append(StudentList list, StudentAttribute *attr);
student_ret_t student_list_remove(StudentList *__restrict list,
				  StudentObject object);
student_ret_t student_list_remove_with_num(StudentList *__restrict list,
					   student_base_t number);
void student_list_sort_by_score(StudentList list);
void student_list_clear(StudentList *__restrict list);
void student_list_delete(StudentList *__restrict list);
StudentObject student_list_get_last(StudentList list);
StudentObject student_list_get_with_num(StudentList list,
					student_base_t number);
StudentObject student_list_generate(StudentList *list_generator);
student_base_t student_list_count(StudentList list);
student_bool_t student_list_is_empty(StudentList list);


#endif // __STUDENT_H
