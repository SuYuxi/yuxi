from django.test import TestCase

# Create your tests here.
import datetime
from django.utils import timezone

from django.urls import reverse
from .models import Question

def create_question(question_text, days):
	time = timezone.now() + datetime.timedelta(days=days)
	return Question.objects.create(question_text=question_text, pub_date=time)

class QuestionMethodTests(TestCase):
	
	def test_index_view_with_no_questions(self):
		response = self.client.get(reverse('polls:index'))
		self.assertEqual(response.status_code, 200)
		self.assertContains(response, "No polls are available.")
		self.assertQuerysetEqual(response.context['latest_question_list'], [])

		
	def test_index_view_with_future_question_and_past_question(self):
		create_question(question_text="Past question.", days=-30)
		create_question(question_text="Future question.", days=30)
		response = self.client.get(reverse('polls:index'))
		self.assertQuerysetEqual(
			response.context['latest_question_list'],
			['<Question: Past question.>']
			)	

	def test_index_view_with_two_past_question(self):
		create_question(question_text="Past question 1.", days=-30)
		create_question(question_text="Past question 2.", days=-5)
		response = self.client.get(reverse('polls:index'))
		self.assertQuerysetEqual(
			response.context['latest_question_list'],
			['<Question: Past question 2.>', '<Question: Past question 1.>']
			)

class QuestionIndexDetailTests(TestCase):
	def test_detail_view_with_a_past_question(self):
		past_question = create_question(question_text='Past Question.', days=-5) 
		url = reverse('polls:detail', args=(past_question.id,))
		response = self.client.get(url) 
		self.assertContains(response, past_question.question_text)

	def test_detail_view_with_a_future_question(self):
		future_question = create_question(question_text='Future question.', days=5) 
		url = reverse('polls:detail', args=(future_question.id,))
		response = self.client.get(url)
		self.assertEqual(response.status_code, 404)

